#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t *create_playlist() // return a newly created doubly linked list
{
    // DO NOT MODIFY!!!
    playlist_t *playlist = (playlist_t *)malloc(sizeof(playlist_t));
    playlist->list = create_list();
    playlist->num_songs = 0;
    playlist->last_song = NULL;
    return playlist;
}

void delete_playlist(playlist_t *playlist) // delete the playlist
{
    // DO NOT MODIFY!!!
    delete_list(playlist->list);
    free(playlist);
}

music_queue_t *create_music_queue() // return a newly created queue
{
    // DO NOT MODIFY!!!
    return create_queue();
}

void clear_music_queue(music_queue_t *q) // clear the queue q
{
    // DO NOT MODIFY!!!
    delete_queue(q);
}

void add_song(playlist_t *playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
    if (where == -1)
    {
        insert_front(playlist->list, song_id);
    }
    else if (where == -2)
    {
        insert_back(playlist->list, song_id);
    }
    else if (where >= 0)
    {
        insert_after(playlist->list, song_id, where);
    }
    playlist->num_songs = playlist->list->size;
}

void delete_song(playlist_t *playlist, int song_id) // TODO: remove song id from the playlist
{
    delete_node(playlist->list, song_id);
    playlist->num_songs = playlist->list->size;
}

song_t *search_song(playlist_t *playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
    return search(playlist->list, song_id);
}

void search_and_play(playlist_t *playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
    song_t *ptr = search(playlist->list, song_id);
    if (ptr != NULL)
        play_song(song_id);
    playlist->last_song = ptr;
}

void play_next(playlist_t *playlist, music_queue_t *q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
    if (q->front == NULL)
    {
        if (playlist->last_song == NULL || playlist->last_song->next == NULL)
        {
            // play_song(playlist->list->head->data);
            playlist->last_song = playlist->list->head;
        }
        else
        {
            // play_song(playlist->list->head->data);
            playlist->last_song = playlist->last_song->next;
        }
        play_song(playlist->last_song->data);
    }
    else
    {
        play_from_queue(q);
    }
}

void play_previous(playlist_t *playlist) // TODO: play the previous song from the linked list
{
    if (playlist->num_songs != 0)
    {
        if (playlist->last_song == NULL || playlist->last_song->prev == NULL)
        {
            playlist->last_song = playlist->list->tail;
        }
        else
        {
            playlist->last_song = playlist->last_song->prev;
        }
        play_song(playlist->last_song->data);
    }
}

void play_from_queue(music_queue_t *q) // TODO: play a song from the queue
{
    play_song(q->front->data);
    q->front = q->front->next;
}

void insert_to_queue(music_queue_t *q, int song_id) // TODO: insert a song id to the queue
{
    enqueue(q, song_id);
}

void reverse(playlist_t *playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
    song_t *ptr1 = playlist->list->head;
    song_t *ptr2 = ptr1->next;
    playlist->list->tail = ptr1;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    playlist->list->head = ptr1;
}

void k_swap(playlist_t *playlist, int k) // TODO: swap the node at position x with node at position x+k upto the point where x+k is less than the size of the linked list
{
    int x, y = 0;
    song_t *ptr = playlist->list->head;
    song_t *cpt;
    song_t *temp;
    for (x = 0; (x + k) < playlist->num_songs; x++)
    {
        cpt = ptr;
        y = 0;
        while (y < k)
        {
            cpt = cpt->next;
            y++;
        }
        temp = ptr->next;
        ptr->next = cpt->next;
        if (k == 1)
            cpt->next = ptr;
        else
            cpt->next = temp;
        temp = ptr->prev;
        if (k == 1)
            ptr->prev = cpt;
        else
            ptr->prev = cpt->prev;
        cpt->prev = temp;
        if (ptr->prev != NULL)
            ptr->prev->next = ptr;
        if (ptr->next != NULL)
            ptr->next->prev = ptr;
        if (cpt->next != NULL)
            cpt->next->prev = cpt;
        if (cpt->prev != NULL)
            cpt->prev->next = cpt;
        if (cpt->prev == NULL)
            playlist->list->head = cpt;
        if (ptr->next == NULL)
            playlist->list->tail = ptr;
        ptr = cpt->next;
    }
}

void shuffle(playlist_t *playlist, int k) // TODO: perform k_swap and reverse
{
    k_swap(playlist, k);
    reverse(playlist);
}

song_t *debug(playlist_t *playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction x.e with the next pointer. No need to check for cycles in the backward pointer.
{
    song_t *slow = playlist->list->head;
    song_t *fast = playlist->list->head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            song_t *meet = slow;
            song_t *start = playlist->list->head;
            while (start != meet)
            {
                start = start->next;
                meet = meet->next;
            }
            return start;
        }
    }
    return NULL;
}

void display_playlist(playlist_t *p) // Displays the playlist
{
    // DO NOT MODIFY!!!
    display_list(p->list);
}

void play_song(int song_id)
{
    // DO NOT MODIFY!!!
    printf("Playing: %d\n", song_id);
}