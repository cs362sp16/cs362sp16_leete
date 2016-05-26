import subprocess
import os

nullf = open(os.devnull,'w')

dominion1dir = "../cs362sp16_folgerd/dominion/"
dominion2dir = "../cs362sp16_leete/dominion"

dominions = [(dominion1dir, "folgerd"), (dominion2dir, "leete")]

subprocess.call(["make clean; make all"], shell=True)

testexes = []

for (d, n) in dominions:
	c1 = "cd " + d + "; make clean; make all"
	subprocess.call ([c1], shell=True)
	c2 = "cd " + d + " ; gcc -o " + n + "test testdominion.c dominion.o rngs.o interface.o --coverage -lm" 
	subprocess.call ([c2], shell=True)
	subprocess.call(["cd " + d + " ;ls ; echo '\n\n\n\n'"],shell=True)
	testexes.append (d + n + "test")

numTests = 100

print (testexes)

for t in range(1,numTests+1):
	print ("test/seed #", t)
	outfiles = []
	for e in testexes:
		eout = open(e+".out",'w')
		print ("file:",e)
		print (os.path.exists(e))
		subprocess.call(["./" + e], stdout=eout, stderr = nullf)
		eout.close()
		outfiles.append(e+".out") 
		r = subprocess.call(["diff " + outfiles[0] + " " + outfiles[1]], shell=true, stderr = nullf, stdout = nullf)
		if (r != 0):
			print ("difference detected, aborting")
			break