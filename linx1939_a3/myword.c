/**
 * -------------------------------------
 * @file  myword.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-02-11
 *
 * -------------------------------------
 */
#include "myword.h"
#include "mystring.h"
#include <string.h>
#include <stdio.h>

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

int create_dictionary(FILE *fp, char *dictionary) {

	if (fp == NULL)
		return -1;
	char line[1000];
	char delimiters[] = " .,\n\t\r";
	char *token;
	int count = 0;
	dictionary[0] = '\0';

	while (fgets(line, 1000, fp) != NULL) {

		str_lower(line);
		str_trim(line);

		token = (char*) strtok(line, delimiters);

		while (token != NULL) {
			strcat(dictionary, token);
			strcat(dictionary, ",");
			count++;
			token = strtok(NULL, delimiters);
		}

	}
	return count;

}

BOOLEAN contain_word(char *dictionary, char *word) {

	BOOLEAN temp1 = 0;

	if (word == NULL || *word == '\0') {
		return 0;
	} else {
		char temp[20] = { 0 };
		strcat(temp, ",");
		strcat(temp, word);
		strcat(temp, ",");

		if (strstr(dictionary, temp)) {
			temp1 = 1;
		}

	}

	return temp1;
}

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {

	WORDSTATS ws = { 0 };
	char line[MAX_LINE_LEN];
	char delimiters[] = ".,\n\t\r";
	char *word_token;

	while (fgets(line, MAX_LINE_LEN, fp) != 0) {
		ws.line_count++;

		str_lower(line);

		word_token = (char*) strtok(line, delimiters);

		while (word_token != NULL) {
			ws.word_count++;

			if (contain_word(dictionary, word_token) == FALSE) {
				int found = 0;

				while (found < ws.keyword_count
						&& strcmp(word_token, words[found].word) != 0) {
					found++;
				}

				if (found < ws.keyword_count) {
					words[found].count++;
				} else {
					strcpy(words[found].word, word_token);
					words[found].count = 1;
					ws.keyword_count++;
				}
			}

			word_token = strtok(NULL, delimiters);
		}
	}

	return ws;

}
