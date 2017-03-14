# QLearning Using C++ and Python
Well, for now, this repo include an simple instance using Q-Learning Algorithm to teach robot get out from a room:
![PicName](http://ofwzcunzi.bkt.clouddn.com/BTQHZVxEOLWftJ3T.png)
The purpose of robot is get rid out of room and get into No. 5 space which is the outside.
And our Q-Learning robot work very well with this!!!
After 500 episode, we get an convergence Q matrix, and when you input and initial room of robot, he can using this map get out of room correct!!!!
```
-- updated Q matrix: 
0   0   0   0   400 0   
0   0   0   320 0   500 
0   0   0   320 0   0   
0   400 256 0   400 0   
320 0   0   320 0   500 
0   400 0   0   400 500 
[INFO] Episode: 999
-- step 0: initial state: 4
-- step 0: next action: 5
-- updated Q matrix: 
0   0   0   0   400 0   
0   0   0   320 0   500 
0   0   0   320 0   0   
0   400 256 0   400 0   
320 0   0   320 0   500 
0   400 0   0   400 500 
Q convergence matrix:
0   0   0   0   400 0   
0   0   0   320 0   500 
0   0   0   320 0   0   
0   400 256 0   400 0   
320 0   0   320 0   500 
0   400 0   0   400 500 
please input robot locate room: 
1
1->5->out
please input robot locate room: 
2
2->3->1->5->out
please input robot locate room: 
4
4->5->out
please input robot locate room: 
```

# Install and Play with it

To test our Q-Learning algorithm, you can:

```
git clone https://github.com/jinfagang/Q-Learning.git
```

and mkdir build:
```
mkdir build
cd build
```

and then cmake and make source code:
```
cmake ..
make -j8
```

last and the exciting moment:
```
./Q-Learning
```

You will get a Q-Learning Robot!!!

# We Implement using Full-Network-Training-Like

As we all know, Q-Learning is actually not like nerual network, but we did it in an neural network way, our Q-Learning structure is just like training a model in Deep-Learning method!!
For instance, we have also something like epoch which we called episode, which means a series of events:
```
[INFO] Episode: 894
-- step 0: initial state: 1
-- step 0: next action: 5
-- updated Q matrix: 
0   0   0   0   400 0   
0   0   0   320 0   499.999 
0   0   0   320 0   0   
0   400 256 0   400 0   
320 0   0   320 0   499.999 
0   400 0   0   400 499.999 
[INFO] Episode: 895
-- step 0: initial state: 3
-- step 0: next action: 2
-- step 1: initial state: 2
-- step 1: next action: 3
-- step 2: initial state: 3
-- step 2: next action: 4
-- step 3: initial state: 4
-- step 3: next action: 0
-- step 4: initial state: 0
-- step 4: next action: 4
-- step 5: initial state: 4
-- step 5: next action: 0
-- step 6: initial state: 0
-- step 6: next action: 4
-- step 7: initial state: 4
-- step 7: next action: 0
-- step 8: initial state: 0
-- step 8: next action: 4
-- step 9: initial state: 4
-- step 9: next action: 3
-- step 10: initial state: 3
-- step 10: next action: 4
-- step 11: initial state: 4
-- step 11: next action: 5
-- updated Q matrix: 
0   0   0   0   400 0   
0   0   0   320 0   499.999 
0   0   0   320 0   0   
0   400 256 0   400 0   
320 0   0   320 0   499.999 
0   400 0   0   400 499.999 
[INFO] Episode: 896
-- step 0: initial state: 0
-- step 0: next action: 4
-- step 1: initial state: 4
-- step 1: next action: 3
-- step 2: initial state: 3
-- step 2: next action: 1
-- step 3: initial state: 1
-- step 3: next action: 5
-- updated Q matrix: 
0   0   0   0   400 0   
0   0   0   320 0   499.999 
0   0   0   320 0   0   
0   400 256 0   400 0   
320 0   0   320 0   499.999 
0   400 0   0   400 499.999 
```

# Future Work

This Q-Learning repo will be maintained, and we will add it more functional and powerful, you can train your own Q-Learning model using this tiny tool, not bother anything. And most important thing is that, Q-Learning is a very very intelligence way then other machine learning method!!

# License

this work is implement by Jin Fagang, if you repost it or distribute it, please add this anounce and follow the Apache License.
For any question, you can contact me via wechat: `jintianiloveu`.