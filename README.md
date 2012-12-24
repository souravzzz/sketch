sketch
======
***

[Sketch](http://en.wikipedia.org/wiki/Count-Min_sketch) is a probabilisitc data structure that maintains counts from a stream.

You can read up on the basics of sketch [here](https://sites.google.com/site/countminsketch/home/faq).

Note that count-min sketch is always positively biased, so I added a very simple `normalize()` method that reduces the error quite a lot.

`sketch.cpp` contains the implementation for the data structure.

`runthru.cpp` does a run through (duh) - you will be able to see how the data structure behaves at each step.

`demo.cpp` will give you a good idea about its accuracy. Try it with and without the `normalize()` call and different amount of memory.
