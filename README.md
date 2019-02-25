# preciseplanner (v0.3)
- This command line program will help a user plan out upcoming concerts and music events. 
  It will allow the user to input music events, with the corresponding artists, start
  times, and their dates and sort and organize them all in a data
  file. The user will be able to use this program to add more events to the
  file, check for the next upcoming event, see all shows within a specific time frame,
  and more.
  
# TODO LIST
- Finish addShow function
- Finish printShow() and printSchedule() functions. 
- Filter for already existing shows when adding a show 

# Ideas / Goals:
- Option to open / go to URL to purchase tickets for an event.
- Separate events that you already have tickets purchased to ...
- Clear out events that have already passed, or archive them.
- Filter for already existing shows.
- include command line options. (getoptlong library ? )
- option to list out all events, maybe even within a specific time frame? or
within just the specific month?
- Use a vector to store them? (or more ideal structure)
- Report conflicting dates (just in case same show is added twice)
- Festival class that extends show, holds lineup of artists. 

# Contributors
- Makefile targets that currently work: testCompare , testAdd, and testPrint . 
- Search code for TODO notes and incomplete functions.
