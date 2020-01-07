# sensors_workshop_iaac

Sensor and DSP workshop notes for MRAC.

Get started following the instructions below:

## Prerequisites

**1** Have Anaconda installed with **Python 3.7**:

![](https://i.imgur.com/eZL8BXw.png)

:::info
You can find a pre-compiled **distribution** here:

https://www.anaconda.com/distribution/
:::

**2** This won't be a **git and code workshop**, so we have two options here for code-sharing. If you have a terminal application with which you are familiar: bash, oh-my-zsh, powershell, gitbash...  follow instructions 2.a..., and then go to 3 (skip 2.b). If you are not familiar with the terminal and git, skip 2.a and jump to 2.b and follow up to 3:

**2.a. Option for terminal users**
2.a.1 You can clone the git repository:
    
```
git clone git@github.com:oscgonfer/sensors_workshop_iaac.git
```

**2.a.2** Then setup a conda environment, using the  environment.yml file in the repository folder:

```
cd sensors_workshop_iaac
conda env create -f environment.yml
...
source activate sensor_dsp
```

**2.a.3** Launch jupyter in the repository folder by typing:


```
jupyter notebook
```

**2.b. Option for non-terminal users**

**2.b.1** Download the git repository:

![](https://i.imgur.com/TrZTJBx.png)

**2.b.2** Open **Anaconda Navigator**
**2.b.3** Go to **Environments** and click on **Import**:

![](https://i.imgur.com/fiBBp4q.png)

**2.b.4** Select the yml file in the repository and give a name to your environment. **Don't use spaces!**. A good name is: _sensor_dsp_

**2.b.5** Go to **Home** and Launch **Jupyter Notebook**:

![](https://i.imgur.com/cDrHsvo.png)

**3.** 🎉 If you see a browser tab open with something like this, open one of the .ipynb files. If there is no error, you are all set!

![](https://i.imgur.com/3kovixl.png)

![](https://i.imgur.com/YkBY9LK.png)

## References

- Python beginner's guide: https://wiki.python.org/moin/BeginnersGuide
- Conda documentation: https://docs.conda.io/projects/conda/en/latest/index.html
- Install an environment from an environment yml file: https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#creating-an-environment-from-an-environment-yml-file
- Notes on Convolution from DSP Guide: "The Scientist and Engineer's Guide to Digital Signal Processing, copyright ©1997-1998 by Steven W. Smith. For more information visit the book's website at: www.DSPguide.com"
- Scipy documentation: https://docs.scipy.org/doc/scipy/reference/#