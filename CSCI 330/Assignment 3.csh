#! /bin/csh

#Name: Joe Dan Parker
#CSCI 330
#Prof. Derek Erdmann
#Assignment: 3

#Variables:
set testfile = (`ispell -l < $1`)
set incorrect = ()
set correct = ()
@ count1 = 0
@ count2 = 1

#Create the file "memory" in the home directory
#if it does not yet exist
touch ~/memory

#loop through each word in testfile for future comparison
foreach misspelled ($testfile)
	#initialize the return variable, defaulted at 0
	@ return = 0
	loop through the memory file for future comparison
	foreach memory (`cat ~/memory`)
		#check if the current word, if misspelled is in the memory file
		#if it is, return true, otherwise return false
		if ($misspelled == $memory) then
			@ return = 1
			break
		else
			@ return = 0
		endif
	end

	#if the last comparison returned false
	#prompt the user to check the spelling
	#if it is correct, add the word to the
	#memory file, otherwise add the corrected
	#spelling and the misspelled words into
	# their respective arrays below
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
#display the misspelled words and their corrections
echo ""
echo "MISPELLED:	CORRECTIONS:"
echo ""
while($count2 <= $count1)
	echo "$incorrect[$count2]		$correct[$count2]"
	@ count2++
end

