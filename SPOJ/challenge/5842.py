a=[11,12,13,14,15,21,22,23,24,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55]
def main():
	for i in range(input()):
		x=raw_input()
		l=len(x)-1
		for j in range(l):
			b=ord(x[j])-65
			if b>=0:print a[b],
		print a[ord(x[l])-65]
	return 0
if __name__=="__main__":
	main()
