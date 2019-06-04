--Map-file--
Level =
{
	Items = 
	{
		{
			Name = "Red Key",
			Description = "A key painted the color red.",
			Useable = true,
			Flag = "N"
		},
		{
			Name = "Screw driver",
			Description = "A screw driver.",
			Useable = true,
			Flag = "N"
		}
	},
	Doors = 
	{
		{
			Name = "Locked Red door",
			Locked = true,
			Description = "A door that is painted red.",
			Key = "Red Key"
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
			Events = {},
			Description = "A magical test room",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = false,
			South = true,
			Pos_x = -1,
			Pos_y = 2,
			Objects = 
			{
				
			},
			Events = {},
			Description = "Another magical test room",
			exitRoom = false
		}
	}
}