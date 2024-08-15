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

# 8/7/24
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

# 8/10/24
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

# 8/14/24
![image](https://github.com/user-attachments/assets/5425b93b-92a4-4cd0-bd70-015a7fc457a9)
nat's cat's but
![image](https://github.com/user-attachments/assets/b2ebd890-aeb4-4d36-a445-cdecee6312d2)

- Richie: C++ implmentation of linear and quardatic curve fitting then the integer overflow attacked
- Nat: Working on ST link
- Damian: Dep sheet worked on
  - fixed STM sheet (WAS JUST GRIM SHEET REFRENCE)
  - Found a buzzer that may kill richie
  - Bonuse meme:![image](https://github.com/user-attachments/assets/63226aac-e59a-4a94-8f00-00a639139dc9)


