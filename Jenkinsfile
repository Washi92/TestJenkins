pipeline {
    triggers {
      pollSCM '*/1000 * * * *'
    }
    stages {
         stage('Check Dependencies') {
            steps {
                sh '''
                python3 --version
                cmake --version
                pip install -r requirements.txt
                '''
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
