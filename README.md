# Social-Friends
<img src="https://user-images.githubusercontent.com/72460876/170507549-f5c16095-f1e9-4556-b1ad-79e63f058b5b.png" width="20" height="20">  University project:

* This project was made with C. 
* To solve this problem I used tables and worked with neighbor arrays. 
* For more information about the project I used enough comments inside the code so it could be easier the code to be understood.
* Downbelow is a pseudocode, explaining the functions.

# Pseudocode

**This program calculates the best time that stathis can come to the party and see most bands<br>**

```
function merge(array Bands, Argument l, Argument m, Argument r){
  Get the slitted array from mergeSort and make two arrays that have
  the right and left side of Bands array.
  Compare their values and sorts them (ascending order).
  
  return to mergeSort ascending order array
end
}
function mergeSort(array Bands, Argument l, Argument r){
    Divide the input array into two halves and save into the Bands array,
    Call mergeSort for the two halves, and then merge the two sorted halves.
    
    return to main ascending order array
  end
}
In the main function {
  ComeMetalBands has the time where the band came to the party.
  LeaveMetalBands has the time where the band left.
  Sort these arrays using mergeSort (ascending order).
  Compare comeMetalBands with leaveMetalBands and find the highest frequency.
  I save it into max .
  Position has the time that comeMetalBands had the highest frequency.
  print results
}
```
