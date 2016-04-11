DESCRIPTION
********************************************************************************
TM Follow adds sitewide and per user links that link to various social networking 
sites. The links reside in two blocks. The TM Follow Site block lists all the 
links for the site itself, and by default is visible on all pages. The TM Follow
User block lists all the follow links for the user and is visible only on user
profile pages. There is a setting in the TM Follow Site block to have it not
display on user profile pages.

INSTALLATION
********************************************************************************
Enable the module at admin/build/modules, then go to user/admin/permissions to 
set which roles are allowed to edit the sitewide follow links, edit own follow
links, edit all user follow links, or administer TM follow. Go to
admin/structure/block to enable the blocks. TM user follow links can be edited at
user/%/tm_follow, whereas sitewide follow links are at admin/config/tm_follow

RECOMMENDED ADD ON
********************************************************************************
It is recommended to enable a module such as external [1] that will pop open
the follow links in a new tab or window; target="_blank" is not used since it
does not validate.

[1] http://drupal.org/project/external

SOCIAL NETWORKS
********************************************************************************
Here's a list of the currently supported social networks:
 - Dribbble
 - Facebook
 - Flickr
 - Google+
 - Instagram
 - LinkedIn
 - Pinterest
 - Tumblr
 - Twitter
 - Vimeo
 - YouTube
 - Xing