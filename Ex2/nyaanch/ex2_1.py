import numpy as np
# import os
# import random
from multiprocessing import Process

def par(i):
    # os.system('./ex2_1.exe' + str(a))
    np.savetxt('py' + str(i) + '.txt', ['Hello ' + str(i)], fmt = '%s')

# for i in range (10): Process(target = par, args=(random.randint(0,9), i)).start()
for i in range (10): Process(target = par, args=(i,)).start()