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


## 9/11/24
- damian died
- Its now called Brainsor mod
- We're a real team :tada:
- Gotta re spec
  -  steal backplane plane power / cut standalone power
  -  make sandwich plane requirements -> tell peeps to make sandwich plane 
  -  steal brain board continuity detection circuits
  -  new stm32?? [big bois](https://www.st.com/en/microcontrollers-microprocessors/stm32h7-series.html)
    - external osciallator scary
  -  damian wants doom on the module
-  Figure out a date for the presentation
-  
### Little Plane Requirements
- Power circuitry
  - Input:
    - 2S-3S (whatever powermod take)
  - Output:
    - the backplane power stuff
      - logic level
      - deployment signal level
- Backplane Compatible Pinout (just supplies power)
- **NO ETHERNET NEEDED** (no one to talk to :( )

![image](https://github.com/user-attachments/assets/5fb2b6d6-4db5-44f5-a375-20a8731ef07c)

## 9/18/24
![image](https://github.com/user-attachments/assets/fadb820e-406b-4a87-8654-8c24849cf780)

- Magnetometers are wierd
- do strange things to i2c busses. surely nothing bad will happen
- The Opps got damian
- How do we want to do accelerometer
  - we fw the adxl375 in conjunction with the lsm6dsm
- What Processor :crab: no more vocore :crab:
  - wizzy or integrated ethernet?
  - both??????? 0ohm resitor bridge so we can have two implementations to double our chances of it working? is that gonna screw up ethernet (our track record with ethernet isn't good)
  - STM32H745/755 or STM32H747/757 (dual core models)
  - dont need them graphics, 747/757
  - dont need crypto/hash, 747
  - BI, XI, ZI (diff packages)
  - LQFP is cooler 

### Things to bring up  
- what kinda little plane?
  - do we give you reqs, or do we get reqs passed down from on high
  - power only littleplane, littleplane that just connects this to power mod
  - ![image](https://github.com/user-attachments/assets/19a9c33a-22a7-4ca8-9798-2b8c99d6fe15)
  - w h a t i s h a p p e n n i n g
- what package do we rock with?
  - 


  - 
### DEADLINES

| Thing | Date |
| ----- | ---- |
| PDR | Sept. 30th | 
| Design Changes Done/CDR | Oct. 14th | 
| Schematics Done / Review 1 | Oct. 28th |
| Schematic Review 2 | Nov. 4th |
| Schematic Review 3 | Nov. 11th |
| Layout Review 1 | Nov. 25th | 
| Layout Review 2 | Dec. 2nd | 
| Board Ordered | Dec. 16th |



## 9/22/24
- slept
- Watched the lord of the ringds instead of meeting
- got yevfluenced

![image](https://github.com/user-attachments/assets/d90d787f-ddb5-4958-9a1d-b330e7e1aedc)
![image](https://github.com/user-attachments/assets/096ad3e1-ac63-49cd-8f14-3685c0faa985)

## 9/29/24
- Presentation grind
![image](https://github.com/user-attachments/assets/8337901f-76fb-4e23-8eb6-e190aad23882)


## 10/9/24
- [ ] Ricihe - make a todo list
- [ ] nat -   altium
- [ ] richie stmcube
## Real Todo list for real
- [x] Decide on STM
- [x] Decide on QSPI
- [ ] Research buzzer more harder
- [ ] gyro, is it good?
- [ ] update lucidchart
- [ ] what mac-phy thingy do we want

![image](https://github.com/user-attachments/assets/ea6899d7-2b47-4e78-a77c-54a534051a21)

![image](https://github.com/user-attachments/assets/b1eb416d-d024-4e1d-9345-5d21bccd2265)

## 10/16/24
### Updates
Nat: Eeped
Damian: Eeped
Richie: Got stabbed, went to art musuem and rock and roll hall of fame
- Got Event Detection working on open rocket flights
### Mintues:
- No more MODS  
  - MINIE: BTB or STDC14?
  - ![image](https://github.com/user-attachments/assets/e646bccb-41af-4a67-a1ac-573e44afe0fc)
  - if we have stdc14, can buy converter and be compatible with j link. [Adapter](https://www.segger.com/products/debug-probes/j-link/accessories/adapters/stdc14-adapter/)
  - BTB is rad tho
- Thinking about mac-phy  
  - "Uh" - Nat
  - Lmao just copy the nucleo whatre they gonna do stop us


![image](https://github.com/user-attachments/assets/a6027e3b-aab9-4e45-85bb-eb60c2c93b0e)


## 10/27/24
![image](https://github.com/user-attachments/assets/b441e0ee-bc37-4fe6-8abf-b08316ee9215)

### Updates:
- Nat  
  - STM in
  - PHY in
  - Buzzer fixed
- Richie
  - did robotics
  - a lil bit of flight controller work
- Damian
  - Did nothing (hes not here to defend himself)

Nats internet died
Damian died

## 10/30/24
Oh shit we have no memes no wonder we're struggling.

![image](https://github.com/user-attachments/assets/e463deb1-cd10-4cbc-9254-f9e56a168f48)

![image](https://github.com/user-attachments/assets/f97d144f-3004-4100-bc40-bc9a3f8cc4ee)


![image](https://github.com/user-attachments/assets/cb1306d3-d183-4b6f-b9aa-cc00d4136a8a)

Thigns to do:

- Richie
  - Altimeter ground level calibration (find pressure at ground level at start, make AGL from that)
  - Make IMU 9.81 m/s calibrated
