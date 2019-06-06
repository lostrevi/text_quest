--Map-file--

-- test level --

-- file notes
-- Resrived flags are N = do nothing | R = Redo (Same as N but it will redo the event if they go back into the room)
-- L flag as well this is a lose flag will end loop
--	 These are put in the Flags table for the event
-- Objects are both rooms and items you can but both in remeber a room must have a direction in lower case
--	n = north w,e,s i think you get it so when added a door to a room enter it like "nDoor" Door being the name of the door
-- and n being the wall it is on
--
--



Level =
{
	Items = 
	{
		{
			Name = "Red Key",
			Description = "a key painted the color red.",
			Useable = true,
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Screw driver",
			Description = "a screw driver.",
			Useable = true,
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Hey dumb ass don't press the big red button. you'll die dumb ass.",
			Description = "Note with red text on it",
			Useable = false, --think this needs to be false
			is_note = true, -- NOTES HAVE WHAT THEY SAY IN Name AND WHAT THEY LOOK LIKE IN Description
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
			Name = "Welcome",
			Event_text = "You find your self in a cave.",
			Options = 
			{
				"Ok...",
				"Right...",
				"Well..."
			},
			Add_flags = -- must be = to the number of options
			{
				"N", --when it sees an N flag it will do nothing
				"N",
				"N"
			}
		},
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
		},
		{
			Flag_Active = "N",
			Name = "Death_button",
			Event_text = "A button is on the wall it says DEATH on it should i push it?",
			Options =
			{
				"Yeah because i hate being able to live.",
				"No i don't want to die"
			},
			Add_flags =
			{
				"L",
				"R"
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
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 1,
			Objects = 
			{
				"nLocked Red door" --the facing char is shoved in front like so
			},
			Events = {},
			Description = "A room with a door painted Red blocking the north path.",
			exitRoom = false
		},
		{
			North = false,
			West = false,
			East = false,
			South = false,
			Pos_x = 0,
			Pos_y = 2,
			Objects = 
			{
				"Hey dumb ass don't press the big red button. you'll die dumb ass." --yeah kinda dumb but should work and this is only forl oading
			},
			Events = {},
			Description = "A hallway.",
			exitRoom = false
		},
		{ --somthing broke fix it
			North = true,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 3,
			Objects = 
			{
				
			},
			Events = {"Death_button"},
			Description = "A room with a big red button that says do not push",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = true,
			South = true,
			Pos_x = 1,
			Pos_y = 2,
			Objects = 
			{
				
			},
			Events = {"Vent_control"},
			Description = "A control room of somekind",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = false,
			South = true,
			Pos_x = -1,
			Pos_y = 2,
			Objects = 
			{
				"wMetal Vent"
			},
			Events = {},
			Description = "A room with a vent on the west facing wall",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = false,
			South = true,
			Pos_x = -2,
			Pos_y = 2,
			Objects = 
			{
				
			},
			Events = {},
			Description = "A magical exit room",
			exitRoom = true
		}
	}
}