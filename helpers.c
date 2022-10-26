// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    if(fraction[0] == '1')
    {
        if(fraction[2] == '8')
        {
            return 1;
        }
        else if(fraction[2] == '4')
        {
            return 2;
        }
        else if(fraction[2] == '2')
        {
            return 4;
        }
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    else if(fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    return 0;
}







// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    int octave = note[strlen(note)-1] - '0';  // cant use atoi as it wants a string, not a charcter.
    // octave -= 48; // adjust ascii to the int value required.
//if note is D4 when it is 2 characters. note=2, so octave is note[2-1]=note[1]='4'=52 in terms of ascii. now we minus '0'=48 to convert it to-(52-48)=4. now you get the int value 4 of octave.





    //determining frequency of a note in an octave
    //declaring frequency as double.
    double frequency=0.0;

    switch(note[0])
    {
        case 'C':
        frequency= 440.0* pow(2.0, -9.0/12.0);
        break;

        case 'D':
        frequency= 440.0* pow(2.0, -7.0/12.0);
        break;

        case 'E':
        frequency= 440.0* pow(2.0, -5.0/12.0);
        break;

        case 'F':
        frequency= 440.0* pow(2.0, -4.0/12.0);
        break;

        case 'G':
        frequency= 440.0* pow(2.0, -2.0/12.0);
        break;

        case 'A':
        frequency= 440.0* pow(2.0, -0.0/12.0);
        break;

        case 'B':
        frequency= 440.0* pow(2.0, 2.0/12.0);
        break;

        default :
            return 0;
    }
  // Loop to shift octave
    if(octave > 4)
    {
        for (int i=0, n=octave -4; i<n; i++)
        {
            frequency *= 2.0;
        }
    }
    else if(octave < 4)
    {
        for (int i=0, n=4-octave; i<n; i++)
        {
            frequency /= 2.0;
        }
    }

    switch(note[1])
    {
        case ('#'):
        frequency *= (pow(2.0, (1.0 / 12.0)));
        break;

        case('b'):
        frequency /= (pow(2.0, (1.0 / 12.0)));
        break;
    }

    int freq= round(frequency);
    return freq;

}




// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
     // If s represents a rest, return true; otherwise return false.

    //if(strlen(s) == 0)
    if(strncmp(s, "", 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}
