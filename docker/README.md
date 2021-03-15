
# Dockerfiles

Here, you'll find Dockerfiles for building ROS1 and ROS2 images. They are explicitly set up to build a *ROS1 Melodic or ROS2 Foxy* image as these were used during development. However, these versions can easily be changed by editing the dockerfile and stating any other version to be required. This would involve changing only a minor subset of one line for each of the dockerfiles. 

Specifically, you can change *FROM ros:foxy* to *FROM ros:eloquent* or any other alteration involving a **correct** ROS version. 

**NOTE**: that the respective ROS1 and ROS2 Dockerfiles are created with a purpose, as their correct setup for robot-runner to be able to run, involve different steps. Therefore only alter the ROS1 dockerfile to any other ROS1 version, and do the same for the ROS2 dockerfile.

# Build ROS Docker Images

**NOTE** that Docker must be already installed. If you do not know how, please check [this](https://docs.docker.com/engine/install/ubuntu/).

Example with ROS2+Gazebo: 
```bash
$ git clone git@github.com:S2-group/ros-configurations.git
$ cd ros-configuration/docker/ros2/gazebo/large/
$ docker build -t <image name> .
```
If you want to build a ROS1 image, please use the path *ros-configuration/docker/ros1* instead.

You can check your Docker images:

```bash
$ docker images | grep ros
```

You should get something like the following (with seconds/minutes ago, of course):

```
ros                 foxy            06184ad8a88a        2 weeks ago         6GB
```

# How to Run a Docker Image

After the following command, you will get the bash shell in the container.

```bash
$ docker exec -it <image name> /bin/bash
```

# How to Commit Image Changes

Get a running container:

```bash
$ docker container ls
```

The result will be something like the following:

```
CONTAINER ID        IMAGE                  COMMAND                  CREATED             STATUS              PORTS               NAMES
03624e51eafe        ros-turtlebot:latest   "/ros_entrypoint.sh …"   27 minutes ago      Up 27 minutes                           clever_cerf
```

Commit the container as image (replace the container ID):
```bash
$ docker commit 03624e51eafe <image name>
```

<b>Note that if you do not commit, all your changes will be lost.</b>


# How to Push to Docker Hub

We are currently using the repository [michelalbonico](https://hub.docker.com/u/michelalbonico/).

Let us assume you have the following image on your machine:

```bash
$ docker images
REPOSITORY                              TAG                 IMAGE ID            CREATED             SIZE
michelalbonico/ros-turtlebot            latest              8735c59fb3fc        35 minutes ago      1.6GB
```

If you want to push any changes in this image, use the following command:

```bash
$ docker push michelalbonico/ros-turtlebot:latest
```
Note that you need to be a collaborator (ask [me](mailto:bsd.albonico@gmail.com)).


