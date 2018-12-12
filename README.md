### Simple velocity/acceleration scenario (a1)

![Alt accident_a1](images/accident_a1.svg)

* Based on [this paper](https://drive.google.com/file/d/1QDbfbPimx4J_werIiUyXG3ZoOR6K9eps/view?usp=sharing)
* Begin recording accelerometer information and looking for potential accidents only above 15mph
* Ignore any acceleration events below a magnitude of 4G's
* This acceleration change should be enough to detect minor accidents, and is well below the threshold for airbag deployment (~60G's)
* Note: in the event of a sudden stop (driver initiated), although the change in velocity might be large, the actual acceleration event is small because the velocity change occurs over a longer time (unlikely to be greater than 4G's)
