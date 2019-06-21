--Map-file--

--Main game file --

-- file notes
-- Resrived flags are N = do nothing | R = Redo (Same as N but it will redo the event if they go back into the room)
-- L flag as well this is a lose flag will end loop
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
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Blue Key",
			Description = "a key painted the color blue.",
			Useable = true,
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Screwdriver",
			Description = "a nice Screwdriver",
			Useable = true,
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Green Skull",
			Description = "a green skull",
			Useable = true,
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Blue Skull",
			Description = "a Blue skull",
			Useable = true,
			is_note = false,
			Flag = "N"
		},
		{
			Name = "Red Skull",
			Description = "a Red skull",
			Useable = true,
			is_note = false,
			Flag = "L"
		},
		{
			Name = "Wrench",
			Description = "a nice Wrench",
			Useable = true,
			is_note = false,
			Flag = "W"
		},
		{
			Name = "From Nnow on Never Touch Red or else you will be dead.",
			Description = "A Note",
			Useable = false, --think this needs to be false
			is_note = true, -- NOTES HAVE WHAT THEY SAY IN Name AND WHAT THEY LOOK LIKE IN Description
			Flag = "N"
		},
		{
			Name = "red paper",
			Description = "a red peice of papaer.",
			Useable = true, --think this needs to be false
			is_note = false, -- NOTES HAVE WHAT THEY SAY IN Name AND WHAT THEY LOOK LIKE IN Description
			Flag = "L"
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
			Name = "Big Blast door",
			Locked = true,
			Description = "A huge blast door.",
			Key = "NOTHING",
			Active_Flag = "F" -- N is nothing and should never be active.
		},
		{
			Name = "Statue is holding a sun",
			Locked = true,
			Description = "a statue is holding a sun",
			Key = "NOTHING",
			Active_Flag = "S" -- N is nothing and should never be active.
		},
		{
			Name = "Locked Blue door",
			Locked = true,
			Description = "door that is painted Blue.",
			Key = "Blue Key",
			Active_Flag = "N" -- N is nothing and should never be active.
		},
		{
			Name = "Vent",
			Locked = true,
			Description = "a vent that is screwed in.",
			Key = "Screwdriver",
			Active_Flag = "N" -- N is nothing and should never be active.
		},
		{
			Name = "Metal Gate",
			Locked = true,
			Description = "a metal Gate with a gear holding it shut.",
			Key = "NOTHING",
			Active_Flag = "G"
		},
		{
			Name = "Magic Door",
			Locked = true,
			Description = "a metal door with 2 hand prints on being Red and other other being Blue.",
			Key = "NOTHING",
			Active_Flag = "B"
		},
		{
			Name = "Green pedestal",
			Locked = true,
			Description = "a green pedestal attacked to the wall. Looks like it can open.",
			Key = "Green Skull",
			Active_Flag = "N"
		}
	},
	Events = 
	{
		{
			Flag_Active = "N",
			Name = "Welcome",
			Event_text = "You awake to find yourself in a room.",
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
			Name = "Leaving",
			Event_text = "You can see Glimmering light to the north!",
			Options = 
			{
				"I'm out of here."
			},
			Add_flags = -- must be = to the number of options
			{
				"N" --when it sees an N flag it will do nothing

			}
		},
		{
			Flag_Active = "N",
			Name = "Notice Me Swrew",
			Event_text = "You notice a vent to the West and on the other side of the vent you see a screw driver.",
			Options = 
			{
				"Ok",

			},
			Add_flags = -- must be = to the number of options
			{
				"N" --when it sees an N flag it will do nothing

			}
		},
		{
			Flag_Active = "N",
			Name = "Generator power on",
			Event_text = "You see a generator do you power it on?",
			Options = 
			{
				"Yes",
				"No"

			},
			Add_flags = -- must be = to the number of options
			{
				"N", --when it sees an N flag it will do nothing
				"R"
			}
		},
		{
			Flag_Active = "W",
			Name = "Gas fix",
			Event_text = "The pipe that is leaking gas can be closed using your wrench! Do you do this?",
			Options = 
			{
				"Yes",
				"No"

			},
			Add_flags = -- must be = to the number of options
			{
				"F", --when it sees an N flag it will do nothing
				"R"
			}
		},
		{
			Flag_Active = "N",
			Name = "New Room1",
			Event_text = "A head of you you see the a statue Move in front of a passage way. The statue is holding a sun.",
			Options = 
			{
				"Neat..",
				"Well...",
				"Ok..."
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
			Name = "Gate_control",
			Event_text = "You find a terminal with a button on it. Do you want to press it?",
			Options = 
			{
				"Ok...",
				"No"
			},
			Add_flags = -- must be = to the number of options
			{
				"G", 
				"R" --when it sees an R it will keep the event active reset it for say.
			}
		},
		{
			Flag_Active = "N",
			Name = "Sun_control",
			Event_text = "A switch on the wall with a sun on it. Do you flip it?",
			Options = 
			{
				"Yes",
				"No"
			},
			Add_flags = -- must be = to the number of options
			{
				"S", 
				"R" --when it sees an R it will keep the event active reset it for say.
			}
		},
		{
			Flag_Active = "N",
			Name = "Magic_door_event",
			Event_text = "A door with to hand prints one being Red and the other being black what do you do?",
			Options = 
			{
				"Touch the Red.",
				"Touch the Blue.",
				"Do nothing."
			},
			Add_flags = -- must be = to the number of options
			{
				"L",
				"B",
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
			West = false,
			East = false,
			South = false,
			Pos_x = 0,
			Pos_y = 1,
			Objects = 
			{
				"nLocked Red door"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = false,
			South = true,
			Pos_x = -1,
			Pos_y = 1,
			Objects = 
			{
				
			},
			Events = 
			{
				"Gate_control"
			},
			Description = "A dark room.",
			exitRoom = false
		},
				{
			North = true,
			West = false,
			East = false,
			South = true,
			Pos_x = 1,
			Pos_y = 1,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = false,
			East = false,
			South = false,
			Pos_x = 2,
			Pos_y = 1,
			Objects = 
			{
				"sMetal Gate","eLocked Blue door","nVent"
			},
			Events = 
			{
				
			},
			Description = "With doors all around",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = true,
			South = true,
			Pos_x = 3,
			Pos_y = 1,
			Objects = 
			{
				"Wrench"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = true,
			Pos_x = 2,
			Pos_y = 0,
			Objects = 
			{
				"Red Key"
			},
			Events = 
			{

			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = true,
			South = false,
			Pos_x = 2,
			Pos_y = 2,
			Objects = 
			{
				"Green Skull"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 2,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A new set of rooms.",
			exitRoom = false
		},
		
		-----------------------ROOM SET 2 ----------------------------------
		
		{
			North = false,
			West = false,
			East = false,
			South = false,
			Pos_x = 0,
			Pos_y = 3,
			Objects = 
			{
				"nStatue is holding a sun"
			},
			Events = 
			{
				"New Room1"
			},
			Description = "A room with a statue is holding a sun to the north.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = true,
			South = true,
			Pos_x = 1,
			Pos_y = 3,
			Objects = 
			{
				"From Nnow on Never Touch Red or else you will be dead."
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = false,
			South = true,
			Pos_x = -1,
			Pos_y = 3,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = false,
			South = false,
			Pos_x = -2,
			Pos_y = 3,
			Objects = 
			{
				"wVent"
			},
			Events = 
			{
				"Notice Me Swrew"
			},
			Description = "A room where you can see a screwdriver on the other side of a vent.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = false,
			South = true,
			Pos_x = -3,
			Pos_y = 3,
			Objects = 
			{
				"eVent","Screwdriver"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = false,
			South = false,
			Pos_x = -4,
			Pos_y = 3,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = -2,
			Pos_y = 2,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = true,
			South = true,
			Pos_x = -3,
			Pos_y = 2,
			Objects = 
			{
				"Blue Key"
			},
			Events = 
			{
				"Sun_control"
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = false,
			South = false,
			Pos_x = -4,
			Pos_y = 2,
			Objects = 
			{
				"eVent"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = false,
			East = true,
			South = true,
			Pos_x = -2,
			Pos_y = 1,
			Objects = 
			{
				"wMagic Door"
			},
			Events = 
			{
				"Magic_door_event"
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = false,
			South = true,
			Pos_x = -3,
			Pos_y = 1,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = false,
			South = true,
			Pos_x = -4,
			Pos_y = 1,
			Objects = 
			{
				"red paper"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 4,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A new set of rooms.",
			exitRoom = false
		},
		
		---------------------- SET 3 -----------------------------------------
		
		{
			North = false,
			West = false,
			East = false,
			South = false,
			Pos_x = 0,
			Pos_y = 5,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = false,
			South = true,
			Pos_x = -1,
			Pos_y = 5,
			Objects = 
			{
				"Red Skull"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = false,
			East = true,
			South = true,
			Pos_x = 1,
			Pos_y = 5,
			Objects = 
			{
				"Blue Skull"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 6,
			Objects = 
			{
				"nGreen pedestal",
			},
			Events = 
			{
				
			},
			Description = "A room with a green pedestal.",
			exitRoom = false
		},
		
		
		---------------------------- SET Fianl ---------------------------------
		{
			North = false,
			West = false,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 7,
			Objects = 
			{
				"nBig Blast door"
			},
			Events = 
			{
				
			},
			Description = "A dark room.",
			exitRoom = false
		},
		{
			North = true,
			West = true,
			East = false,
			South = true,
			Pos_x = -1,
			Pos_y = 7,
			Objects = 
			{
				
			},
			Events = 
			{
				"Generator power on","Gas fix"
			},
			Description = "A room with a pipe leaking gas and a generator.",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 8,
			Objects = 
			{
				"Leaving"
			},
			Events = 
			{
				
			},
			Description = "A glimmering light ahead must be the exit!",
			exitRoom = false
		},
		{
			North = false,
			West = true,
			East = true,
			South = false,
			Pos_x = 0,
			Pos_y = 9,
			Objects = 
			{
				
			},
			Events = 
			{
				
			},
			Description = "A bright room.",
			exitRoom = true
		}
		
	}
}