--Map-file--
Level =
{
	Items = 
	{
		{
			Name = "Red Key",
			Description = "a key painted the color red.",
			Useable = true,
			Flag = "N"
		},
		{
			Name = "Screw driver",
			Description = "a screw driver.",
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
			North = true,
			West = false,
			East = false,
			South = false,
			Pos_x = 0,
			Pos_y = 2,
			Objects = 
			{
				
			},
			Events = {},
			Description = "A hallway.",
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