# Meeting Summaries
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
