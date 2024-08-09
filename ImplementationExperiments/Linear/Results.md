Linear Curve Fitting

Implementing this as shown in stepwise.cpp

$$ m = \frac{N \sum \left(xy \right) - \sum(x) \sum(y)}{N \sum(x^2) - (\sum(x))^2} $$

$$b = \frac{\sum(y) - m\sum(x)}{N}$$

where: 
- $N$ = number of samples in the window
- $x$ = time samples
- $y$ = altitude samples

For each sample, calculating $m$ and $b$ takes the following operations:

| Operation | Number |
| --------- | ------ |
| Add       | 4      |
| Subtract  | 7      |
| Multiply  | 7      |
| Divide    | 2      |


# Building
```sh
$ g++ -std=c++23 -Wall -Werror -pedantic -fsanitize=undefined stepwise.cpp -o stepwise
```
