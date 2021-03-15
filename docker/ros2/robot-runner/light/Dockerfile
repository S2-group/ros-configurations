FROM ros:foxy
RUN sudo apt update && sudo apt-get install -y python3-pip wget unzip
RUN export CLOUDSDK_PYTHON=python3
COPY ./ros2_rr_requirements.txt ./
RUN python3 -m pip install -r ./ros2_rr_requirements.txt
RUN wget --no-check-certificate --content-disposition https://github.com/S2-group/robot-runner/archive/master.zip
RUN unzip /robot-runner-master.zip
RUN mv /robot-runner-master /robot-runner
WORKDIR /robot-runner
