pipeline {
    agent { 
        node {
            label 'docker-agent-python'
            }
      }
    triggers {
      pollSCM '*/5 * * * *'
    }
    stages {
        stage('Build') {
            steps {
                echo "Building.."
                sh '''
                python3 --version
                pip install -r requirements.txt
                '''
                sh '''
                echo "doing build stuff.."
                '''
            }
        }
        stage('Test') {
            steps {
                echo "Testing.."
                sh '''
                python3 fireApp.py
                '''
            }
        }
        stage('Deliver') {
            steps {
                echo "Deliver...."
                sh '''
                echo "doing delivery stuff.."
                '''
            }
        }
    }
}
