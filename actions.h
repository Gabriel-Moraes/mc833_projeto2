#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

typedef struct Profile {
	char email[30];
	char firstName[20];
	char lastName[20];
	char residence[30];
	char academicBackground[50];
	char graduationYear[4];
	char skills[300];
	char professionalExperience[300];
} Profile;

int treatClientActionRequest(int sock, char* request, struct sockaddr_in clientAddress); 
int createProfileAction(int sock, char* response, struct sockaddr_in clientAddress);
int addProfessionalExperienceAction(int sock);
int listGraduatedOnCourseAction(int sock);
int listHasSkillAction(int sock);
int listGraduatedOnYearAction(int sock);
int listAllProfilesAction(int sock);
int getProfileInfoAction(int sock, char* request,  struct sockaddr_in clientAddress);
int removeProfileAction(int sock);
