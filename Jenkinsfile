pipeline {
    agent any
    triggers {
      pollSCM '*/1000 * * * *'
    }
    stages {
        stage('Software Versions') {
            steps {
                sh '''
                uname -s
                cat /etc/os-release
                git --version
                python3 --version
                cmake --version    
                ls -ltra
                '''
            }
        }
        stage('Main Build') {
            steps {
                echo "Building.."
                sh '''
                mkdir build
                cmake .
                echo "cmake build"
                cmake --build .
                '''
            }
        }
        stage('Linux Build') {
            agent {
                node {
                    label 'docker-agen-cmake'
                }                
            }
            stages {
                stage('Check requirements'){
                    steps {                       
                        sh '''
                        uname -s
                        cat /etc/os-release
                        python3 --version
                        cmake --version
                        ninja --version
                        g++ --version
                        which cmake
                        pwd
                        ls -ltra
                        '''                
                    }
                }
                stage('Linux Build'){
                    steps {
                        echo "Building for Linux..."
                        // Linux build commands
                        sh '''
                        cmake .
                        echo "cmake build"
                        cmake --build . --config RelWithDebInfo
                        '''                
                    }
                }
                stage('Deliver') {
                    steps {
                        echo "Deliver...."
                        sh '''
                        mv appMain ./appMainLinux
                        ls -ltra
                        '''  
                        archiveArtifacts(allowEmptyArchive: true, artifacts: 'appMainLinux')
                    }
                }
                stage('Test') {
                    steps {
                        echo "Testing Linux..."
                        sh '''
                        ./appMainLinux
                        '''
                    }
            }
        }
            
        stage('Test') {
            steps {
                echo "Testing.."
                sh '''
                ./appMain
                '''
            }
        }
        stage('Deliver') {
            steps {
                echo "Deliver...."
                archiveArtifacts(allowEmptyArchive: true, artifacts: 'appMain')

            }
        }
    }
}
