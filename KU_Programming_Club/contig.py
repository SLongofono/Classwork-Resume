import sys

def buildTable(word, rows, cols, mark=False):
	temp = []
	table = []
	index = 0
	for i in range(rows):
		table.append([])
		for j in range(cols):
			if mark:#building the visited field
				table[i].append(0)
			else:   #building a maze
				if word[index] == "x":
					table[i].append(1)
				else:
					table[i].append(0)
			index = index + 1
	if not mark:
		print "Built the maze as follows:"
		print table
	else:
		print table
	return table

def explore(field, marked, start):
		#in marked, 1's are visited, 0's are not
		rows = len(field)
		cols = len(field[0])
		#check if start is a space
		if field[start[0]][start[1]] == 0:
			#move on
			return 0
		#check if start is in a known area (don't count it)
		elif marked[start[0]][start[1]] != 0:
			return 0

		#otherwise, spread out as far as possible and return 1
		else:	
			#mark position visited
			marked[start[0]][start[1]] == 1
			
			#get available moves
			moves = []
			getMoves(field, marked, start, moves)
			
			#while there are possible moves, traverse them
			iters = 0
			while len(moves) > 0 and iters < 5:
				print field
				iters = iters + 1
				#mark the top item of the 'stack'
				current = moves.pop()
				print "removing " + str(current) + " from the moves list"
				print marked
				try:
					print "value of position " + str(current) + ":"
					print str(marked[current[0]][current[1]])
					marked[current[0]][current[1]] == 1
				except:
					print "mark failed"
				print marked
				getMoves(field, marked, current, moves)
		return 1
			
def getMoves(field, marked, position, moves):

	print "looking at position " + str(position)

	#look up
	if(position[0]-1>=0):
		print "can move up"
		if (field[position[0]-1][position[1]] == 1) and (marked[position[0]-1][position[1]]==0):
			moves.append((position[0]-1,position[1]))
			print "can move up, adding (" + str(position[0]-1) + "," + str(position[1])
	#look right
	if (position[1]+1 < len(field[0])):
		if (field[position[0]][position[1]+1] ==1 ) and (marked[position[0]][position[1]+1]==0):
			moves.append((position[0], position[1]+1))
			print "can move right, adding (" + str(position[0]) + "," + str(position[1]+1)

	#look down
	if (position[0]+1<len(field)):
		if (field[position[0]+1][position[1]] == 1) and (marked[position[0]+1][position[1]]==0):
			moves.append((position[0]+1,position[1]))
			print "can move down, adding (" + str(position[0]+1) + "," + str(position[1])
	#look left
	if (position[1]-1>=0):
		if (field[position[0]][position[1]-1] == 1) and (marked[position[0]][position[1]-1]==0):
			moves.append((position[0], position[1]-1))
			print "can move left, adding (" + str(position[0]) + "," + str(position[1]-1)
	print "Moves after this iteration : " + str(len(moves))
	
if len(sys.argv )<4:
	print "Invalid entry"
	sys.exit(0)
elif(len(sys.argv[3])!=(int(sys.argv[2])*int(sys.argv[1]))):
	print "Invalid entry"
	sys.exit(0)
else:
	rows = int(sys.argv[1])
	cols = int(sys.argv[2])
	rawfield = sys.argv[3]
	field = buildTable(rawfield, rows, cols)
	marked = buildTable(rawfield, rows, cols, True)
	contigs = 0
	for i in range (rows):
		for j in range(cols):
			contigs = contigs + explore(field, marked, (i,j))

	print "Found " + str(contigs) + " contiguous sections"
sys.exit(0)	
