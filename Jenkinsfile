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
            }
        }
        stage('Test') {
            steps {
                echo "Testing.."
                sh '''
                python3 fireApp.py
                python3 fireApp.py --name=Washi
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
