# preciseplanner (v.09)
- This command line program will help a user plan out concerts and music events. 
  It will allow the user to input music events, with the corresponding artists, start
  times, and their dates and sort and organize them all in a data
  file. The user will be able to use this program to add more events to the
  file, check for the next upcoming event, see all shows within a specific time frame,
  and more. 
- Be aware the default make target is not yet complete, and only the testTime target is functional at the moment.
  
# TODO LIST
- Fix timetoString() in Show.cpp
- Overload > operator for show in Show.cpp

# Ideas / Goals:
- Option to open / go to URL to purchase tickets for an event.
- Separate events that you already have tickets purchased to .. (save order numbers)
- Clear out events that have already passed, or archive them.
- Sort by dates 
- Filter for already existing shows.
- include command line options. (getoptlong library ? )
- option to print out what the next event is.
- use file reading / processing to accomplish.
- option to list out all events, maybe even within a specific time frame? or
within just the specific month?
- Store the objects in binary? Then load them in and reinterpret them. 
- Use a vector to store them? (or more ideal structure)
- Report conflicting dates (just in case same show is added twice)
