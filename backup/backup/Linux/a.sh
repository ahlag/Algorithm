#!/bin/bash
is_ignored_file() {
	case "$1" in
		*~ | *.bak | *.txt)
			echo 0
			;;
		*)
			echo 1
	esac
}

is_ignored_file ./b.txt
is_ignored_file b
is_ignored_file b
