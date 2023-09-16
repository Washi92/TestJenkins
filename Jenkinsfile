pipeline {
    agent any
    triggers {
      pollSCM '*/1000 * * * *'
    }
    stages {
        stage('Software Versions') {
            steps {
                sh '''
                git --version
                python3 --version
                cmake --version    
                ls -ltra
                '''
            }
        }
        stage('Build') {
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
                archiveArtifacts(allowEmptyArchive: true, artifacts: 'appMain.exe')

            }
        }
    }
}
