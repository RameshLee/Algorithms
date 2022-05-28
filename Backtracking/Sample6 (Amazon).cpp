// 250k+ total?

// base salary, annual bonus, stock grant => 156k + (62k, 46k) + 40 RSU => total = 224,587 (first year)
// stocks will vest at percentages of 5,15,40,40 over 4 years.
// amazon sde 2 base caps at 160k even after performance bonus. Switch to sde3 later to increase base cap ASAP.

More questions:
// performance bonus per year?
// increase vacation days?
// vancouver/toronto?
// interview feedback? areas to improve?
// sde vs applied scientist track? Opportunities for switching.
// paternity, marriage and sabbatical leave?
// working hours in amazon? Mon-Fri?
// who is my manager? same person who interviewed me?
// what are the next steps?
// Anything else I should know about before signing the offer?

Questions:
// location: vancouver/toronto?, team: middle mile routing?, WFH?
// work-life balance: working hours, how strict is office presence?
// vacation: paid, unpaid, paternity, sick leave, sabbatical? (3 weeks vacation, 6 days paid + sick)
// salary: percentage of salary at hand? any unknown deductions?
// career trajectory: how long does it take from sde 2 to sde 3?
// relocation package, signing bonus, and other perks? ==> max(2.5k+help + 30 days package, 6.8k)
// 85$ per month => parking/transportation
// 65$ per month => phone allowance
// 10% amazon

budget problem replies:
// based on market research, speaking to colleagues, my expected salary range for my background is this.
// Just to ensure that I payback loans/PR initial amount: like to invest myself at amazon for the long run.
// Do not want to look others. helpful for us both.
// 1) very specialized routing experience, PHD degree, lots of experience.
// 2) to bridge the gap: sign on bonus or any other package?
// informal offer letter?

negotiation templates:
// - salary => [minimum, happyNumber] how did you arrive at that number? How high can you go?:)
// - Can we round that salary to whole amount? :)
// - Thank you for that. But I would be really excited to accept a higher amount. considering specialized experience and fit.
// - I am looking for a competitive offer. And, for me, that's around this amount. Is there any way to get closer to that? :)
// - That's a little lesser than what I was expecting. I was thinking closer to 180k. Can we meet in the middle?
// - I would love to join. This is my no.1 company. But, the compensation is too lower than my minimum.
// - I am very excited about this position. But, this compensation doesn't work for me.
// Is there anything you can do? Anyone you could talk to? Can you get back tomorrow or later this week?
// I would really appreciate it. Thank you so much.
// - with my 6 YOE and specialized experience + fit as talking with HR, I feel like I'm uniquely positioned to help routing team.
// - Perhaps you could also consider my performance at current position. I am an IVADO laureate, winner of Canada's AI fellowship in 2020.
// perhaps you can consider all these? Is there any way we can get closer to the industry benchmark?
// To compensate for the range, can we perhaps increase the vacation days?

// specialized experience in routing + PHD degree + IVADO Laureate (one of the 20 people worldwide)

// - Can we talk again on Monday?

// Amazon, Vancouver
//  OA
1) Palindrome linked list
2) Check password strength

// On-site
1) 30 min LP, 30 min coding (DS)
    - Top K highest salaried employees. (priority_queue + custom comparator)
    - Follow ups: dept-wise employees? avoid same person in multiple departments? (hashMap + set + custom comparator)

2) 30 min LP, 30 min coding (Problem-solving)
    - Design functions to store word-synonym pair & retrieve all synonyms of a word. (dynamic disjoint set + graph traversal)
    - 4 Sum problem. Follow-up: solve it with O(N^2) time complexity. (hashMap + two pointers approach)

3) 30 min LP, 30 min coding (LLD)
    - Purchase validation system: design a class to validate a purchase with all given rules. (polymorphism + pureVirtualFunc)

4) 60 min LP (bar-raiser)
    - Barrage of LPs and grilling into tiny bits of both technical & behavioral aspects of each answer.

5) 60 min LP, 30 min system design (HLD)
    - Design Instagram. (requirements, cache, load balancing, newsfeedGen, etc.)

// Offer
- Received offer in 48 hours. (May 24, 2022)

// Preparation
First FAANG interview.
1) DS & Algo:
    - Textbook: Algorithms by Sanjay Dasgupta. Online resources: geeksforgeeks, programiz, etc.
1) Problem-solving:
    - Leetcode (158 easy + 196 medium + 24 hard = 378 problems, in 3 months).
    - Attended all weekly LC contests after prepping 1 month.
    - Completed all explore cards + amazon interview card in leetcode.
    Tips: solve & revise occasionally. solve both iterative & recursive whenever possible. Review the most-voted solutions.
2) LLD & HLD:
    - Gr*kking the OOD interview and Gr*kking the system design interview.
    Tips: prepare notes & keep revising. pick up patterns b/w questions. read more about crucial system design components. (e.g. CDN, hashing)
3) LPs:
    - Dan Croiter to get a general idea on LPs & STAR pattern.
    - Tailored 10 solid stories & tagged them with suitable amazon LPs.
    - All LPs were from here. https://leetcode.com/discuss/interview-question/437082/Amazon-Behavioral-questions-or-Leadership-Principles-or-LP
    Tips: Smile & be confident. never tell failure to any LP. tell how you exceeded expectations on each LP situation.


System design Interview:-
Design Instagram:
- Social networking web/app in which people can post/share/like/comment pictures/videos/text.

1) Requirements:
    - Functional requirements:
        - User should be able to post text, pictures, and videos.
        - User should be able to follow other users.
        - User should be able to like and comment on other user's posts.
        - Retrieve all media files of a user.
        - User news feed should be generated (based on who they follow & hot topics!)
    - Non-functional requirements:
        - Efficient access to media (pictures and videos).
        - High availability.
        - High consistency (if user has multiple devices).
    - Extended requirements:
        - User should be able to report/block abusive contents.
        - User should be able to enable two-step verification. (security/permissions)
        - Serviceability or Manageability of the system should be higher.
        - User content should not be lost because of any system failures.

2) Design considerations:
    - System is "read-heavy". Ratio of read to write is 5:1.

3) Capacity requirements:
    - Total number of users = 5 Million in total
    - Total active users = 1 Million per day
    - 5 media files are posted by an user every day.
    - 1 media file (text, pic, video) contribute to 1 MB in average.
    - Storage estimates per day = 1M users* 5 files/user * 1 MB/file = 5*10^6 Million bytes every day
    - Storage estimates in total = 5M users * 20 files/user * 1 MB/file * 5 years ==> (Ans) GB storage disk ==> distributed systems
    - Read bandwidth per sec = 1M user * 20 files/user = (Ans) MBPS
    - Write bandwidth per sec = (Ans/5) MBPS

4) System APIs:
    - postMedia(api_key, content, location, time, allowedUsers);
    - followUser(api_key, targetUser, ... ,);
    - interactPost(api_key, post_id, interactionType, OptionalContent, ... ,);
    - retrieveNewsFeed(api_key, location, time,...,); // internally: followedUsers & hotUsers in instagram.

5) Database schema:
    - relational (SQL) vs non-relational (noSQL) databases.
    ==> non-relational database (eg. key-value pair database) // scalability is a priority.

6) High-level design:
    - [Client] --[LB]--> [ProxyServer] --[LB]--> [ApplicationServer1, AS2,..,ASn]
                                                    --[LB]--> [DataBase Server, (DRS) DS2,...,DSn]
                                                    --[LB]--> [MetaData Server, MS2,..,MSn]
                                 -->[AggregationServer,Cache(LRU)]<----
                                 --> [keyGenerationServer]



    - [friend of Client] <-- retrieves news feed

    - postMedia() --> systemAPI

7) Serviceability/Manageability
8) Redundancy ==> improves reliability