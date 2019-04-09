# preciseplanner (v1.0)
- This command line program will help a user plan out upcoming concerts 
and events. It will allow the user to input events, with their corresponding 
names and dates and sort and organize them all into a schedule sorted by dates. 
The user will be able to use this program to add more events to the file, check 
for the next upcoming event, see all shows within a specific time frame, and more.

# Installation 
- First clone and then move into the repository.
```
git clone https://github.com/andrewkassab/preciseplanner
cd preciseplanner
```
- Next, go ahead and run the install script through make.
```
sudo make install
```
- You should be good to go! Feel free to delete the cloned folder after 
your installation.

# USAGE
- planner -a : add shows to the schedule
- planner -r: remove shows from the schedule
- planner -n: print the next show in the schedule
- planner -p: print the schedule
- planner -m (month): print the schedule for current or specified month
- planner -h: display usage
  
# Ideas / Goals:
- Option to open / go to URL to purchase tickets for an event.
- Use more ideal data structure for storing shows ?
- Festival class that extends show, holds lineup of artists. 
- Add edge cases for specific months ( february can't have over 29 days, etc. )
- Access the archived shows through the program itself
