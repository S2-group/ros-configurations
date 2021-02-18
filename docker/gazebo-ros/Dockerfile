FROM ros:eloquent
RUN sudo apt update && sudo apt -y install curl gnupg2 lsb-release wget
RUN curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
RUN sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
RUN sudo apt update
RUN sudo apt -y install ros-dashing-desktop
RUN sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" > /etc/apt/sources.list.d/gazebo-stable.list'
RUN wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
RUN apt-get update
RUN sudo apt-get -y install libgazebo9
RUN sudo apt-get -y install libgazebo9-dev
RUN sudo apt-get -y install gazebo9
RUN sudo apt -y install ros-dashing-gazebo-ros ros-dashing-gazebo-ros-pkgs
RUN sudo apt -y install ros-dashing-turtlebot3-*
RUN sudo apt -y install ros-dashing-rcl ros-dashing-rcl-interfaces ros-dashing-rclc
RUN mkdir -p ~/turtlebot3_ws/src
RUN wget https://raw.githubusercontent.com/ROBOTIS-GIT/turtlebot3/ros2/turtlebot3.repos
RUN vcs import ~/turtlebot3_ws/src < turtlebot3.repos
WORKDIR /
RUN bash /opt/ros/dashing/setup.sh
RUN echo 'export CMAKE_PREFIX_PATH=/opt/ros/dashing/\n\
	cd ~/turtlebot3_ws/\n\
	colcon build --symlink-install\n'\ > setup.sh
RUN echo 'export ROS_DOMAIN_ID=30\n\
	export TURTLEBOT3_MODEL=burger\n\
	export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/turtlebot3_ws/src/turtlebot3/turtlebot3_simulations/turtlebot3_gazebo/models\n\
	source /opt/ros/dashing/setup.sh\n'\ > source.sh
RUN chmod +x setup.sh

