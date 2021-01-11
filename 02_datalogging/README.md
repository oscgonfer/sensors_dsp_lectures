## Presentation

Find it [here](presentations/MRAC_HARDWARE_II_2021_D2.pdf)

## Examples list

- [Reading serial stream from Arduino into python](examples/python_serial.py)
- [Raspberry Pi Digital Sensor](examples/raspberrypi_digital_sensor.py)
- [OpenCV Python Camera Capture](examples/opencv_python_video_capture.py)

## Additional references

- Good OpenCV material: https://www.learnopencv.com

### Anaconda installation

Follow the instructions on Anaconda's website
https://docs.anaconda.com/anaconda/install/linux/


####  Check if the installation was successful

`conda -V`

#### Update if necessary

`conda update conda`

#### Create a new environment

`conda create -n envname python=3.8.5 anaconda`

(where "envname" is the environment name, you can choose what you want)

#### Activate the new environment
`conda activate envname`

#### Deactivate the current environment
`conda deactivate`

#### Rename an environment

We can't do that. We have to clone the env with a another name and delete the old one.

`conda create --name new_name --clone old_name`
`conda remove --name old_name --all`

#### Install a package for the env

`conda install -n envname package`

#### Open the notebook

`jupyter notebook`
