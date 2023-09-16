pipeline {
    agent any
    triggers {
      pollSCM '*/1000 * * * *'
    }
    stages {
        stage('Check-Deps') {
            steps {
                sh '''
                python3 --version
                cmake --version               
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
            }
        }
        stage('Deliver') {
            steps {
                echo "Deliver...."
            }
        }
    }
}
