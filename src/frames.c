/*******************************************************
*   ---------------- frames.c -------------------        *
********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "frames.h"
#include "list.h"

int alloc_frame(List *frames) {
	int 	frame_number, 
			*data;

	if (list_size(frames) == 0)
		//return that there are no frames available.
		return -1;

	else {
		if (list_rem_next(frames, NULL, (void **)&data) != 0)
			// return that a frame could not be retrived
			return -1 ;
		else {
			// store the number of the available frame.
			frame_number = *data	;
			free(data);
		}
	}

	return frame_number;
}

int free_frame(List *frames, int frame_number) {
	int 	*data ;

	// allocate storage for the frame number
	if ((data = (int *)malloc(sizeof(int))) == NULL)
		return -1;

	// put the frame back in the list of available frames.
	*data = frame_number;

	if(list_ins_next(frames, NULL, data) != 0)
		return -1;

	return 0;
}
