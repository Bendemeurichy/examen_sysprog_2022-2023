#!/bin/bash
#
# Changelog:
#     2021-01-11 Add file with timestamp to every commit.
#     2022-01-25 Add installed extensions to commit.
#

#
# e_push commits and pushes all current changes using the first argument and
# the timestamp as commit message.
#
# Argument 1: commit message prefix
#
e_push () {
    timestamp=$(date)
    extensions=$(code --list-extensions)
    message="$1 $timestamp"$'\n\n'"$extensions"
    echo "PUSHING CODE at $timestamp"
    echo "$timestamp" > timestamp.txt
    git add -A
    git commit -m "$message"
    # push the current branch to origin
    git push -u origin HEAD
    if git push -u origin HEAD; then
        return 0
    fi
    echo -e "\e[31mERROR: Indienen faalde!\e[0m"
    return 1
}


#
# e_periodic_push commits and pushes all changes every X seconds with a 
# timestamp as commit message.
#
# Argument 1: interval between commits
#
e_periodic_push () {
    git config credential.helper store
    while true; do
        success="false"
        while [[ "$success" != "true" ]]; do
            if e_push "Automatic commit"; then
                success="true"
            else
                echo -e "\e[31mWe proberen opnieuw over 1 seconde.\e[0m"
                sleep 1
            fi
        done
        echo "FINISHED PUSHING CODE"
        echo "WAITING $1 seconds"
        echo ""
        echo ""
        echo ""
        sleep $1
    done
}


if [[ "$1" == "manual" ]]; then
    echo "MANUAL PUSH"
    e_push "Manual commit"
else
    e_periodic_push "$1"
fi
