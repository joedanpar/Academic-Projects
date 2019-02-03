#! /bin/csh
 
 set testfile = (`ispell -l < $1`)
 set incorrect = ()
 set correct = ()
 @ count1 = 0
 @ count2 = 1
 touch ~/memory
 foreach misspelled ($testfile)
      @ return = 0
      foreach memory (`cat ~/memory`)
           if ($misspelled == $memory) then
                @ return = 1
                break
           else
                @ return = 0
           endif
      end
      if ($return == 0) then
           echo ""
           echo "'$misspelled' is mispelled. Press "Enter" to keep"
           echo -n "this spelling, or type a correction here: "
           set response = $<
           if ($response == "") then
                echo $misspelled >> ~/memory
           else
                @ count1++
                set incorrect = ($incorrect $misspelled)
                set correct = ($correct $response)
           endif
      endif
 end
 echo ""
 echo "MISPELLED:     CORRECTIONS:"
 echo ""
 while($count2 <= $count1)
      echo "$incorrect[$count2]          $correct[$count2]"
      @ count2++
 end