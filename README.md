# Immersive Role-Play Chatbot

## Overview
The Immersive Role-Play Chatbot is an interactive storytelling platform hosted on Telegram. It enables users to create and control immersive role-play scenarios dynamically. Users can define characters, settings, and story progressions to guide the chatbot in delivering a personalized narrative experience. The service leverages AWS infrastructure for scalability and reliability.

## Features
- **User-Defined Role-Play Setup**: Fully interactive and customizable story development controlled by the user.
- **Telegram Integration**: Seamless interaction with the chatbot through the Telegram app.
- **Dynamic Storytelling**: Real-time adjustments to characters, plots, and settings as the story unfolds.
- **AWS Hosting**: Secure, scalable, and reliable hosting in the cloud.

## Architecture
The project is structured as follows:
1. **Frontend**: Telegram bot interface for user interaction.
2. **Backend**: Hosted on AWS, includes:
   - **RPC Services**: Written in C++ for handling story progression and decision-making logic.
   - **Database**: Amazon RDS (Relational Database Service) for storing story data, user preferences, and interactions.
   - **Networking**: A specialized VPC with one private and one public subnet to segregate the database and RPC services. NAT is configured for secure traffic handling.

## Getting Started

### Prerequisites
- **Telegram Bot Token**: Obtain from [Telegram BotFather](https://core.telegram.org/bots#botfather).
- **AWS Account**: Set up an account and configure your CLI.
- **Development Tools**:
  - AWS CDK
  - Docker
  - C++ compiler (e.g., GCC)
  - Python (for auxiliary scripts and integration)

### Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-repo/immersive-roleplay-chatbot.git
   cd immersive-roleplay-chatbot
   ```

2. **Configure AWS CDK**:
   - Install AWS CDK:
     ```bash
     npm install -g aws-cdk
     ```
   - Bootstrap your environment:
     ```bash
     cdk bootstrap aws://<account-id>/us-east-1
     ```

3. **Define the Infrastructure**:
   Modify the `cdk.json` file to declare the stack:
   - Region: `us-east-1`
   - VPC with one private and one public subnet
   - RDS database in the private subnet
   - NAT gateway for traffic routing

   Deploy the infrastructure:
   ```bash
   cdk deploy
   ```

4. **Set Up Telegram Bot**:
   - Create a bot and retrieve the token from Telegram BotFather.
   - Save the token in your environment variables:
     ```bash
     export TELEGRAM_BOT_TOKEN=your_token
     ```

5. **Build and Deploy the Backend**:
   - Build the C++ RPC service:
     ```bash
     mkdir build && cd build
     cmake ..
     make
     ```
   - Dockerize and deploy:
     ```bash
     docker build -t immersive-rpc-service .
     docker run -p 8080:8080 immersive-rpc-service
     ```

6. **Run the Bot**:
   - Start the Telegram bot service:
     ```bash
     python bot.py
     ```

## Usage
- Start a chat with your Telegram bot.
- Define your role-play setup interactively.
- Guide the chatbot as it develops the story in real-time.

## Technology Stack
- **Programming Languages**: C++, Python
- **Frameworks**: AWS CDK, Telegram Bot API
- **Cloud Infrastructure**: AWS (RDS, VPC, EC2, NAT Gateway)
- **Database**: Amazon RDS
- **Deployment**: Docker

## Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature/your-feature
   ```
3. Commit changes:
   ```bash
   git commit -m "Add your message"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/your-feature
   ```
5. Open a pull request.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgements
- Telegram Bot API documentation
- AWS CDK team for infrastructure as code tools
- OpenAI for chatbot logic inspiration


