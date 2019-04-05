# preciseplanner (v0.91)
- This command line program will help a user plan out upcoming 
concerts and music events. It will allow the user to input music 
events, with the corresponding artists, start times, and their 
dates and sort and organize them all in a data file. The user will 
be able to use this program to add more events to the file, check 
for the next upcoming event, see all shows within a specific time 
frame, and more.

# USAGE
- planner -a : add shows to the schedule
- planner -r: remove shows from the schedule
- planner -n: print the next show in the schedule
- planner -p: print the schedule
- planner -m (month): print the schedule for current or specified month
- planner -h: display usage
  
# Ideas / Goals:
- Option to open / go to URL to purchase tickets for an event.
- Filter for already existing shows.
- Use more ideal data structure for storing shows ?
- Festival class that extends show, holds lineup of artists. 

# TODO (Version 1.0)
- Add edge cases for month / days ( february only has 29 .. etc )
- Finish completion script
- Figure out install script
