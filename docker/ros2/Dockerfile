FROM ros:eloquent
RUN sudo apt update && sudo apt-get install -y python3-pip wget
RUN export CLOUDSDK_PYTHON=python3.8
COPY ./ros2_rr_requirements.txt ./
RUN python3 -m pip install -r ./ros2_rr_requirements.txt
RUN mkdir /robot-runner
RUN wget --no-check-certificate --content-disposition https://github.com/S2-group/robot-runner -P /robot-runner
WORKDIR /robot-runner
