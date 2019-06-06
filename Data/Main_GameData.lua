--Map-file--

--Main game file --

-- file notes
-- Resrived flags are N = do nothing | R = Redo (Same as N but it will redo the event if they go back into the room)
--	 These are put in the Flags table for the event
-- Objects are both rooms and items you can but both in remeber a room must have a direction in lower case
--	n = north w,e,s i think you get it so when added a door to a room enter it like "nDoor" Door being the name of the door
-- and n being the wall it is on
--

Level =
{
	Items = 
	{
		{
			Name = "Red Key",
			Description = "a key painted the color red.",
			Useable = true,
			Flag = "N"
		}
	},
	Doors = 
	{
		{
			Name = "Locked Red door",
			Locked = true,
			Description = "door that is painted red.",
			Key = "Red Key",
			Active_Flag = "N" -- N is nothing and should never be active.
		},
		{
			Name = "Metal Vent",
			Locked = true,
			Description = "metal vent with a set of gears holding it shut.",
			Key = "NOTHING",
			Active_Flag = "V"
		}
	},
	Events = 
	{
		{
			Flag_Active = "N",
			Name = "Vent_control",
			Event_text = "You find a terminal with a button on it. Do you want to press it?",
			Options = 
			{
				"Ok...",
				"No"
			},
			Add_flags = -- must be = to the number of options
			{
				"V", 
				"R" --when it sees an R it will keep the event active reset it for say.
			}
		}
	},
	Rooms = 
	{
		{
			North = false,
			West = true,
			East = true,
			South = true,
			Pos_x = 0,
			Pos_y = 0,
			Objects = 
			{
				"Red Key"
			},
			Events = 
			{
				"Welcome"
			},
			Description = "A dark room with brick walls on all sides but north.",
			exitRoom = false
		}
	}
}