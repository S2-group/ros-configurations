# Gazebo + ROS2

Before starting, [here](https://hub.docker.com/_/gazebo) you can check how to run a standalone (without ROS) Gazebo Simulator on Docker.

---

Our image can be found [here](https://hub.docker.com/repository/docker/michelalbonico/gazebo-ros2-foxy), and integrates both, Gazebo+Turtlebot Worlds+ROS2. 

First of all, you need to build a Docker image (<b>attention</b>, it is a large image ~6GB):

```
$ git clone git@github.com:S2-group/ros-configurations.git
$ cd ros-configuration/docker/ros2/gazebo/large/
$ docker build -t gazebo-ros2 .
```

Now you need to configure your OS for Docker to run GUI apps. Note that the right thing would be to connect to the Gazebo server (gzserver) from a remote client (gzclient). However, we want to reduce network overhead. Therefore, we choose to run Docker apps with [Rocker](https://github.com/osrf/rocker).

Install the Rocker:
```bash
$ pip install rocker
```

Running with NVidia display cards:
```bash
$ rocker --nvidia --x11 --home gazebo-ros2
```

Running with other/generic cards:
```bash
$ rocker --devices /dev/dri/card0 --x11 --home gazebo-ros2
```

From now on (if you followed the previous commands) you will be in the Docker container shell.

Set the environment variables:

```bash
# source source.sh
```

Run a simulation example:
```bash
# ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
```

Remember to kill the Gazebo server before running something else:
```bash
# plill gzserver
```

[This](https://emanual.robotis.com/docs/en/platform/turtlebot3/ros2_simulation/) will help you to run a complete experiment with a simulated turtlebot.

----

## Gazebo and ROS(1)

Compile your ROS1+Gazebo+Turtlebot image:

```
$ git clone git@github.com:S2-group/ros-configurations.git
$ cd ros-configuration/docker/ros/gazebo/large/
$ docker build -t ros-gazebo-turtlebot .
```
Run your image:

```bash
$ rocker --devices /dev/dri/card0 --x11 --home ros-gazebo-turtlebot
```
Set the environment variables:

```bash
# source /opt/ros/melodic/setup.sh
```

Follow the section <i>6.1.2</i> of the [Robotis tutorial](https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/). 

----

## Robot Runner and Gazebo

...

## Creating a World (Gazebo Model)

Follow [this](http://gazebosim.org/tutorials?tut=build_world) tutorial.

## Our Models

...

Play with other models available [here](https://github.com/osrf/gazebo_models).


