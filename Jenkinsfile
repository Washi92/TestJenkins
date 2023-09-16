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
        stage('Windows Build') {
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
                        echo "Building for Linux..."
                        // Linux build commands
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
