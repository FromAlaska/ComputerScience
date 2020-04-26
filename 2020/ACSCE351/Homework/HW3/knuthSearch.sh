#/bin/bash
echo "KNUTH STRING SEARCH"
echo "Which method would you like to choose?"
echo "(1) best case method (search for 'bee' in text that has 'bee'"
echo "(2) best case method (search for 'ab' that has various cases of 'ab'"
echo "(3) best case method (search for 'bee' in BeeMovieScript)"
echo "(4) worst case method (random string search)"
echo "(5) rewrite randomly generated string"
echo "(6) exit"

while true; do
    read -p "(6 to exit)>>" ans
    case $ans in
        1 ) ./knuth ./Scripts/beeOnlyScript bee;;
        2 ) ./knuth ./Scripts/abScript ab;;
        3 ) ./knuth ./Scripts/BeeMovieScript bee;;
        4 ) read -p "Put in string to search: " str; ./naive ./Scripts/randomlyGeneratedString $str;;
        5 ) rm -rf ./Scripts/randomlyGeneratedString && touch ./Scripts/randomlyGeneratedString ; echo "rewriting randomly generated string"; python2 ./randomcharactergenerator.py;;
        6 ) exit;;
        * ) echo "Please answer one of the following options. (6) to exit";;
    esac
done
