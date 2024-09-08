# Meeting Summaries
## 7/X/24
- Hey, nat and i are talking about a secret module, wanna join


## 7/17/24:
- High level wiring diagram
- What chips we need
- Minimum requirements for setting off deployment charges
- Planning DND (Damian and Nat's Deployment)
- Planning standalone powermod
- Setup Github
- Began CONOPs (ConOps, CONOPs)

## 7/24/24:
![image](https://github.com/user-attachments/assets/831c8cc7-ae64-49a6-b53e-ae0c9aa0a87e)
- Established polynomial fit is like almost it for predicting apogee :( - Pretty close
## 7/31/24
- Imported Flash chip sheet to Altium
- STMCube Document (in github 🖤)
- We can sort of measure drag so we can add that to our model
- Maybe fitting drag curve can yield apogee?
- Matlab model shows that drag creates a fairly predictible error rate in under estimating altitude, more modeling needed
- What defines a good model
  - At halfway point, predicted apogee should be within 300ft of actual
![image](https://github.com/user-attachments/assets/f9959179-9d7e-42ed-b1b8-b5058d6f1e9f)

## 8/7/24
![image](https://github.com/user-attachments/assets/65e717b5-5c67-4f2b-8167-8758a4bc2b6f)
- Nat: is busy
- forgor abt mach effects
  - Detect Burnout, Detect Out of Mach/big buffer, then we're chilling again
- Bezier Curve Fitting??
- Accepting Defeat?:
  - We can prolly just get away with parabolas
  - s: current time, t: time of apogee
  - as s approaches t, your prediction gets better - drag plays less of a role, youre more of a parabola
  - if your prediction is good enough and your predicted apogee near enough, you can make the call telling any peripherals that its almost apogee time with some degree of certainty
  - now you just gotta implement least squares effeciently :)
![image](https://github.com/user-attachments/assets/9ded0dc5-27c7-4f06-9115-05080ad8c2c4)

## 8/10/24 half meet (altium gang)
![image](https://github.com/user-attachments/assets/061e897d-bb5d-478d-a62e-e204d43ba890)
- Richie: is busy
- Altum meeting, working on power sheet
  - Power SHEET UPDATES
    - Arming switch
    - Mosfetss <-- we may be wrong
    - DEP Signal outs
    - Power switching for dep
    - Working on power switching for internal
  - STM Landing pads?

## 8/14/24
![image](https://github.com/user-attachments/assets/5425b93b-92a4-4cd0-bd70-015a7fc457a9)
nat's cat's but
![image](https://github.com/user-attachments/assets/b2ebd890-aeb4-4d36-a445-cdecee6312d2)

- Richie: C++ implmentation of linear and quardatic curve fitting then the integer overflow attacked
- Nat: Working on ST link
- Damian: Dep sheet worked on
  - fixed STM sheet (WAS JUST GRIM SHEET REFRENCE)
  - Found a buzzer that may kill richie
  - Bonuse meme:![image](https://github.com/user-attachments/assets/63226aac-e59a-4a94-8f00-00a639139dc9)
## 8/21/24
- [Runge-Kutta](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) our way to victory
  - can use actual drag equation and solve it
  - which ODE is the best one (ask donovan, he has opinions)
![makesweet-tl7qkj](https://github.com/user-attachments/assets/7351ea7f-c277-44fc-8c44-a6ec56ee6447)
- Richie: did some open rocketing
- Nat: Groceries
- Damian: no update <- lazy bum
  - Bonuse meme:![image](https://github.com/user-attachments/assets/e9771ed5-c9d3-4d7c-81e1-41fbf272c169)


## 8/25/24 half meet (altium gang)
- ![image](https://github.com/user-attachments/assets/5efc6741-8bbd-4158-a7e7-254d08695055) 
  - Fixed power conflics of 9vbatt and 9v
  - added INA260 for power monitoring 3.3 and 9v needs checked
  - ST LINK ADDED?!?!?!
       -not reall, but component is in
    
## 9/4/24 
- ![image](https://github.com/user-attachments/assets/d3411cf8-431f-4a51-a8e3-e92f6b2611c7)
  - Showed Luis, Christian and Donnovan dep mod over the weekend they liked it and gave a green light for presintation
  - Working on presination for avionics
  - Nat (CUBEMX hell)
  - Richie???
  - Bonus meme:![image](https://github.com/user-attachments/assets/04f39c90-c96f-42e5-9274-5c597609d925)

## 9/8/24
![image](https://github.com/user-attachments/assets/2d5c766f-ecf1-49fb-81a1-90dfb1954989)

Experiment Results: Sucess
- I was tricked into coming to the meeting

- Damian worked on slides, reqs etc
- Debouncing signals
- STLink pain (connecting to the STM32 itself), STM32 work, and wanting to murder the STM people
  - Like, connecting and making sure all the pins across the sheets are connected to the right stm32 pin
- car ![image](https://github.com/user-attachments/assets/c6b6b40c-ccec-4145-a8ea-38dd262ed631)

