## Setup

In order to run the script, you will need to add it to the 'src' folder of your package. This should be located within your workspace under [workspace]/src/[package] -> /src

You will also need to make sure psutil is installed on the turtlebot. Alongside this, create a folder on the turtlebot under /home/ubuntu called "Robot_Data". The python code saves the csv files directly to this folder.

## Running

You will have to source the workspace the file is in initially through:
```bash
$ source /path/to/workspace/setup.sh
```

Then you can run the script using:
```bash
$ rosrun [package name] resource_meter.py
```

Once you terminate this node (CTRL+C) it will finish writing to the .csv file.

It will not overwrite existing files, as each file is timestamped with a unix timecode indictating the start of execution.

Alternatively, you can add this to a launch file through:
```XML
<node pkg="[package name]" name="resource_meter" type="resource_meter.py" output="screen"/>
```

## Reading the data

To access the files, make sure you shut down the turtlebot using the
```bash
$ sudo shutdown
```
command in order to preserve the files that were written to the Micro SD.

Once powered off, you can remove the Micro SD from the turtlebot and mount it on a computer. From the "writable" section, go to /home/ubuntu/Robot_Data to see the files.

## Problems you may encounter

If the program fails to run it could be one of many issues, which can include:

- The psutil Python library is not properly installed
- resource_meter.py is not set to "run as program" within the file properties
- The path to Robot_Data is different, possibly due to the username of the OS on the turtlebot. In this case, you can go into resource_meter.py to manually change the path.
- roscore is not properly set up/running on the remote pc. Make sure ROS_MASTER_URI and ROS_HOSTNAME are properly set on both devices, then run roscore on the remote pc.
