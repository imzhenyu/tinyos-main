/*
 * Copyright (c) 2008 Stanford University.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the Stanford University nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL STANFORD
 * UNIVERSITY OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * This is the file to include in your top level application when using 
 * the tosthread library.  It defines all the tosthread_* commands and 
 * #includes all of the needed header files for the basic tosthread 
 * library calls
 *
 * @author Kevin Klues <klueska@cs.stanford.edu>
 */
 
#ifndef TOSTHREAD_H_INCLUDED
#define TOSTHREAD_H_INCLUDED

#include "thread.h"

/**
 *  tosthread_main()
 *
 *  This in the main entry point thread from which all tosthread applications begin.  
 *  @param	NULL
 */
extern void tosthread_main(void* arg);

/**
 *  tosthread_create()
 * 
 *  This function creates a new tosthread.  
 *  
 *  @param 	t 				A pointer to a thread identifier
 *  @param 	start_routine	The function called when the created thread starts running
 *  @param 	arg				The parameter passed to the start_routine for the created thread
 *  @param 	stack_size		The maximum stack size for this thread
 *  @return					An error code indicating whether the thread could be created or not
 *								SUCCESS		-	The thread has been created
 *							  	FAIL		- 	The thread could not be created
 *								EALREADY	-	The thread identifier is already associated with a
 *												currently active thread
 */
extern error_t tosthread_create(tosthread_t* t, void (*start_routine)(void*), void* arg, uint16_t stack_size);

/**
 *  tosthread_destroy()
 *
 *  This function destroys a tosthread.  
 *  
 *  @param t 				A pointer to a thread identifier
 *  @return					An error code indicating whether the thread could be destroyed or not
 *								SUCCESS		-	The thread has been destroyed
 *							  	FAIL		- 	The thread could not be destroyed
 *								EBUSY		-	The thread holds mutexes so cannot be destroyed
 *												at the moment
 */
extern error_t tosthread_destroy(tosthread_t* t);

/**
 *  tosthread_pause() 
 *
 *  This function pauses a tosthread.  
 *  
 *  @param t 				A pointer to a thread identifier
 *  @return					An error code indicating whether the thread could be paused or not
 *								SUCCESS		-	The thread has been paused
 *							  	FAIL		- 	The thread could not be paused
 *								EBUSY		-	The thread holds mutexes so cannot be paused
 *												at the moment
 */
extern error_t tosthread_pause(tosthread_t* t);

/**
 *  tosthread_resume()
 *
 *  This function resumes a previously paused tosthread.  
 *  
 *  @param t 				A pointer to a thread identifier
 *  @return					An error code indicating whether the thread could be resumed or not
 *								SUCCESS		-	The thread has been resumed
 *							  	FAIL		- 	The thread could not be resumed
 */
extern error_t tosthread_resume(tosthread_t* t);

/**
 *  tosthread_sleep()
 *
 *  This function puts the currently running thread to sleep.  
 *  
 *  @param milli 			The number of milliseconds to sleep for
 *  @return					An error code indicating whether the thread could be put to sleep or not
 *								SUCCESS		-	The thread has been put to sleep
 *							  	FAIL		- 	The thread could not be put to sleep
 */
extern error_t tosthread_sleep(uint32_t milli);

#endif //TOSTHREAD_H_INCLUDED