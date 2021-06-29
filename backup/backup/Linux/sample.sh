while true
do
	echo "Continue? (y/n)"
	read input
	case $input in
		n) break
		   return 1
		   ;;
		y) continue
		   return 2
		   ;;
		*) echo "Please input y or n."
		   ;;
	esac
done
