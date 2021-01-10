# Prefix Sum

* It is an algorithm that calculates the summary of the section by specifying a section.
* Operates as dp, and subtracts the calculated value from the sum of the end index to the sum of the start-1 index.



* there's a useful two-dimension problem.
  * setting start/end x,y axis value
  * presum[0-*end_x*,0-end_y] - presum[0-start_x, 0-start_y] - presum[start_x-end_x,  0-start_y] - presum[0-start_x, start_y-end_y] 

