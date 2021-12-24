This day we will talk about opencv and basic image and video processing.

Make sure you install the requirements in the `examples` folder:

```
pip install -r requirements.txt
```

## Using YOLO

Options: 
- A) Install Darknet: https://pjreddie.com/darknet/install/ 
- A.1) For weird image formats, use it with OPENCV (optional). For this, modify Makefile.
B) If using opencv and opencv-python, it comes already with darknet accessible

### Weights and cfg

Get the weights from [here](https://pjreddie.com/media/files/yolov3.weights):

```
cd extras
wget https://pjreddie.com/media/files/yolov3.weights
```

Get the yolov3.cfg from [here](https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg):

```
cd extras
wget https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg
```

Check in the [Darknet github](https://github.com/pjreddie/darknet/tree/master/cfg) for more cfgs.