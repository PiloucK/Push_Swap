mkdir -p /tmp/push_swap
rm /tmp/push_swap/*.cnt
python3 -c "from itertools import permutations as p ; print('\n'.join([ ' '.join(x) for x in p('12345', 5)]))" | while read -r line; do
	echo -n '`'$line'`: '
	operation=$(./push_swap $line)
	ops_count=$(echo  "$operation" | wc -l)
	echo -n "$line|"$(echo $operation | tr '\n' ',')"\n" >> /tmp/push_swap/$ops_count.cnt
	echo -n "$ops_count ops: "
	echo "$operation" | ./checker $line
done

#!/bin/sh

# test_ps()
# {
#         input="$1"

#         echo "Instruction count: "
# 		./push_swap $input > toto
# 		./push_swap -v $input
#         ./push_swap $input | wc -l
#         echo "Is sorted?"
#         ./push_swap $input | ./checker $input

# }

# test_ps "1 2 3 4 5"
# test_ps "1 2 3 4 5 0"
# test_ps "1 21 2 19 3 17 4 15 5 11"
# test_ps "7 6 5 4 1 3 2"
# test_ps "2 1"
# test_ps "1 2 0"
# test_ps " 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 90 -123 321 234 432 345 543 456 654 567 765 678 -867 789 -9870 9 8 7 6 5 4 3 2 1"
# test_ps " -12 9999 19283112 98782913 -312873 77889 99887 -99887 -77889 2134432 -1232323 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 90 -123 321 234 432 345 543 456 654 567 765 678 -867 789 -9870 9 8 7 6 5 4 3 2 1"

# test_ps "-13755 -5716 85797 -31233 -52655 -45147 9357 -44596 -51172 -7843 -75355 -93724 47974 -30309 25122 20700 -58697 21603 -4176 48326 13606 -99108 50785 26269 34047 91376 -85331 22917 -68677 -57624 -17041 59450 -94431 96526 -17696 -18679 -86753 -16046 -99415 -54596 -96426 37255 -1090 35613 -1259 -57731 64095 32248 -77354 -59254 -84209 20395 71426 64159 27051 87608 -54913 -79172 68698 5485 -15584 3682 59209 -66572 -94428 28803 -61687 7438 -35853 -92331 54349 33477 8340 -49339 -32706 -59225 41805 42346 -2199 -84040 -75506 -81473 38379 47270 47504 -98088 41606 -5046 71239 74407 93382 -70404 36000 61761 26709 -90690 3711 -58004 -71990 -73147"

# test_ps "37547 48458 -92841 -91848 -78670 -51306 79116 27966 22774 -94297 -85880 -537 64054 -96354 -62118 -30611 -97430 -35045 29129 -33305 45839 80662 6923 -1793 59079 -13807 -39165 -37322 -8918 -50668 43166 58681 -56155 59991 15768 70558 -34532 90443 -26595 22151 25450 64887 -62483 -60914 -49175 44007 45706 -48247 -3968 -83578 65364 -6348 -35966 -91154 -47476 42537 29415 -40559 -27088 -91957 52203 48053 -68366 94837 58432 -93053 -8031 -54667 48185 88010 -62247 48925 -13631 3125 93329 -39059 2681 -86798 5540 -83738 -51753 -87079 -12917 40097 21908 -46847 -44875 67500 42686 -75646 3181 -98944 63472 82038 72618 -83691 -80059 49736 34924 39710 -25701 56738 -42695 55117 -3072 -12050 -78317 -2908 -39004 32948 34685 26696 32239 84368 -78162 -58593 97383 -69199 50348 -70694 36809 -72879 71744 -18866 40729 35046 -54660 -77055 28175 24695 68585 -68764 -68238 47768 -49440 -37108 -94473 -54786 -47851 9360 -24571 -13639 -97053 -84351 81861 93364 489 42735 -65736 35761 -97704 -42857 -558 31613 64663 10672 51560 41477 84887 -1265 -15989 -81229 -79167 -74635 51482 -13222 74543 168 96092 -51203 -90681 -14722 23000 1370 12145 58870 9699 20241 42464 -31650 -3005 -61903 -87309 -55966 83644 -30005 25125 77980 -43318 -59809 -23197 11034 -38713 28059 88112 318 -82880 -11429 -78479 77100 74464 97098 -76181 -37357 16122 -79070 8880 89243 45457 70094 29268 -76427 63795 8203 -62951 63412 -6158 -48482 37814 -44866 78640 -94719 -27581 -83619 61460 -43116 43815 23456 -23876 2853 41740 -48080 97653 -64613 1535 -6732 -3472 -96810 -1258 12854 -79517 -57566 -31051 -43954 -57689 82243 -32522 -3402 26204 -2956 -63219 69904 27703 29121 -16425 36235 16444 48861 98370 -61103 11132 21166 -7616 35692 -92518 -10618 -276 -71114 89078 72686 -29423 61085 -13382 63084 71259 64485 -87377 95196 -90668 40985 -33070 4727 48919 10731 -64650 -63808 78757 -94074 -808 33008 -29378 -68674 98557 -10633 -3991 30059 -67776 90572 -22397 10924 -59533 45133 20855 99692 82928 45177 -27379 -78161 17722 -93555 97623 -32836 88499 43360 -59691 -71567 54149 32816 36153 -67407 48376 -5984 -70508 -92668 71005 45520 2711 -39965 55005 -22674 -62992 -83831 93430 -56224 36329 54914 -7775 85208 24512 37986 46498 4893 -55698 -59332 -24919 -40271 -38965 61360 -67205 -45888 -91704 -97629 -85255 -85283 42491 10659 84545 -67317 32033 9372 23324 -94653 62016 88218 -81954 -8239 -54244 7296 61690 -76842 -93055 -775 16123 82956 61990 -41960 -42903 18384 7047 -60582 6058 -89343 8433 -55735 -17466 4583 -27648 31378 36588 -36551 14771 117 92568 -14816 -80783 -54934 2195 44115 -39322 32531 -69178 -79005 20590 73092 -53030 64228 11764 6868 23581 -70732 -62653 -71474 50652 -97126 44611 -87858 -16993 -57786 91747 90850 -99599 20488 14722 -7472 -64109 -53592 91775 49989 -46111 64139 -75960 -40794 84126 -59780 30355 32516 -60065 88075 -81601 -46581 -40057 44855 -89631 85371 -62185 36360 -21380 -53378 88328 33469 -23560 91125 561 -18185 -25216 -1315 -76435 -70246 29686 -63270 -41937 46640 -6780 18575 -37655 -39041 -40884 -65780 -78364 73630 68530 44761 -57402 -88717 39157 88539 36717 -22828 -50365 -34011 30136 10427 -84108 6523 8143 29027 94846 72134 92076 6648 88033 -4326 -6197 -49322 26089 -26765 -6010 32138 16787 63923"
