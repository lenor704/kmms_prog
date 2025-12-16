CPP_FILES="main.cpp menu_items.cpp menu_functions.cpp"
APP=example

if [ -f $APP ]; then rm $APP
fi

g++ $CPP_FILES -o $APP

./$APP