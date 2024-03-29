/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:51:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/10 08:18:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

size_t	abs_index(const char *buffer, const char c);
char	**ft_split(char const *s, char c);
char	**ft_split_set(char const *s, const char *charset);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
size_t	ft_strlen_safe(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strnjoin(char *s1, const char *s2, const size_t n);
char	*ft_strnjoin_free(char *s1, const char *s2, const size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	get_size_strs(char *const *const strs);
ssize_t	index_of(const char *str, const char c);
bool	is_in_str(const char *str, const char c);
char	*replace_str_free(char *src, const char *replace,
			const size_t index, const size_t delete_len);
char	*replace_str(const char *src, const char *replace,
			const size_t index, const size_t delete_len);
bool	streq(const char *str1, const char *str2);
bool	is_suffix_valid(const char *const str, const char *const suffix);
size_t	count_c_in_str(const char *str, const char c);

#endif
